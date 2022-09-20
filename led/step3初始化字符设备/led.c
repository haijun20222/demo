#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>

int led_open(struct inode *, struct file *);
int led_release (struct inode *, struct file *);

#define LED_MA     (500)
#define LED_NUM   (1)
#define LED_MI       (0)
#define E_OK  (0)

struct cdev cdev;//定义字符设备

struct file_operations led_fops=
{
	.owner = THIS_MODULE,
	.open   = led_open,
	.release =led_release,

};

int led_open(struct inode *inode, struct file *file)
{
	printk("driver led open\n ");
	return 0;
}

int led_release (struct inode *inode, struct file *file)
{
	printk("driver led close\n ");
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
          return ret;
     }  

     cdev_init(&cdev, &led_fops);
     ret =  cdev_add(&cdev, devno, LED_NUM);
     if(ret<0)
     {
            printk("  cdev_add fail!!!\n");
	     return ret;
      }

     
     printk("led init regiser successfully!!!\r\n");
     return E_OK;
}


static void led_exit(void)
{
        dev_t  devno = MKDEV(LED_MA,LED_NUM);
        unregister_chrdev_region(devno, LED_NUM);//取消注册
    	printk("led dev unregister successfully !!!\r\n ");
}

module_init(led_init);//模块加载入口声明
module_exit(led_exit);//模块卸载入口声明
MODULE_LICENSE("GPL");//开源免费声明
MODULE_AUTHOR("chenhaijun");


































