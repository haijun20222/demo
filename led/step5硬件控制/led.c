#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<asm/io.h>


int led_open(struct inode *inode, struct file *file);
int led_release (struct inode *inode, struct file *file);
long led_ioctl (struct file *inode, unsigned int cmd, unsigned long args);
void led_on(void);
void led_off(void);
void show_reg(void);

#define LED_MA     (500)
#define LED_NUM   (1)
#define LED_MI       (0)


#define  LED_IMAGIC  'L'
#define LED_ON    _IOW(LED_IMAGIC,1,int)
#define LED_OFF   _IOW(LED_IMAGIC,2,int)


unsigned char * gpio_base;
unsigned char * gpio_pinmax;


#define PINMUX_AUX_DAP4_SCLK_0   0x70003150


#define GPIO3         0x6000D200
#define CNF             0x04
#define OE               0x14
#define OUT            0x24
#define MSK_CNF   0x84
#define MSK_OE   0x94
#define MSK_OUT   0xA4

struct cdev cdev;//定义字符设备

struct file_operations led_fops=
{
	.owner = THIS_MODULE,
	.open   = led_open,
	.release =led_release,
	.unlocked_ioctl = led_ioctl,

};



int led_open(struct inode *inode, struct file *file)
{
	printk("driver led open\n ");
	show_reg();
	return 0;
}

int led_release (struct inode *inode, struct file *file)
{
	printk("driver led close\n ");
	show_reg();
	return 0;
}

long led_ioctl (struct file *inode, unsigned int cmd, unsigned long args)
{
	switch(cmd)
	{
        	case LED_ON:
			led_on();
			printk("led on!!!\r\n");break;
		case LED_OFF:
			led_off();
			printk("led off !!!!\r\n");break;
		 default:
		 	printk("no found cmd\r\n");
			return -1;
	}
	return 0;
}

static int led_init(void)
{
     int ret = 0;
     dev_t  devno = MKDEV(LED_MA,LED_MI);
     ret = register_chrdev_region(devno,LED_NUM, "chj led");
     if(ret < 0)
     {
          printk("register led  dev fail\n!!!");
          goto err1;
     }  

     cdev_init(&cdev, &led_fops);
     ret =  cdev_add(&cdev, devno, LED_NUM);
     if(ret<0)
     {
            printk("  cdev_add fail!!!\n");
	    goto err2;
      }

	gpio_pinmax = ioremap(PINMUX_AUX_DAP4_SCLK_0,8);
	writel((readl(gpio_pinmax) & ~(1<<4) )|1 ,gpio_pinmax);
	if(gpio_pinmax ==NULL)
	{
        	 goto err3;
	}

	gpio_base = ioremap(GPIO3,8);
	if(gpio_base ==NULL)
	{
        	 goto err4;
	}

	writel(readl(CNF+gpio_base)|1<<7,CNF+gpio_base);
	writel(readl(OE+gpio_base)|1<<7,OE+gpio_base);
	writel(readl(OUT+gpio_base)|1<<7,OUT+gpio_base);
	writel(readl(MSK_CNF+gpio_base)|1<<7,MSK_CNF+gpio_base);
	writel(readl(MSK_OE+gpio_base)|1<<7,MSK_OE+gpio_base);
	
     printk("led init regiser successfully!!!\r\n");
err4:
  	iounmap(gpio_base);
err3:
	iounmap(gpio_base);
err2:
 	cdev_del(&cdev); 
err1:
	unregister_chrdev_region(devno, LED_NUM);
  	
     return ret;
}


void show_reg(void)
{
	printk("cnf            = %x\n",readl(gpio_base+CNF));
	printk("oe            = %x\n",readl(gpio_base+OE));
	printk("out            = %x\n",readl(gpio_base+OUT));
	printk("msk_cnf            = %x\n",readl(gpio_base+MSK_CNF));
	printk("msk_out            = %x\n",readl(gpio_base+MSK_OUT));
	printk("msk_oe            = %x\n",readl(gpio_base+MSK_OE));
	printk("gpio_pinmux           = %x\n",readl(gpio_pinmax));
}


void led_on(void)
{
	writel(readl(OUT+gpio_base)|1<<7,OUT+gpio_base);
	printk("out high level light\r\n ");

}

void led_off(void)
{
	writel(readl(OUT+gpio_base)&   ~(1<<7),OUT+gpio_base);
	printk("out low level  extinguish\r\n ");
}

static void led_exit(void)
{
        dev_t  devno = MKDEV(LED_MA,LED_MI);
	iounmap(gpio_pinmax);
	iounmap(gpio_base);
	cdev_del(&cdev); 
        unregister_chrdev_region(devno, LED_NUM);//取消注册
    	printk("led dev unregister successfully !!!\r\n ");
}

module_init(led_init);//模块加载入口声明
module_exit(led_exit);//模块卸载入口声明
MODULE_LICENSE("GPL");//开源免费声明
MODULE_AUTHOR("chenhaijun");






































