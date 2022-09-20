#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>

#define LED_MA     (500)
#define LED_NUM   (1)
#define LED_MI       (0)
#define E_OK  (0)

static int led_init(void)
{
     int ret = 0;
     dev_t  devno = MKDEV(LED_MA,LED_NUM);
     ret = register_chrdev_region(devno,LED_NUM, "chj led");
     if(ret < 0)
     {
          printk("register led  dev fail!!!");
     }  
     printk("led init regiser successfully!!!\r\n");
     return E_OK;
}


static void led_exit(void)
{
        dev_t  devno = MKDEV(LED_MA,LED_NUM);
        unregister_chrdev_region(devno, LED_NUM);
    	printk("led dev unregister successfully !!!\r\n ");
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("chenhaijun");


































