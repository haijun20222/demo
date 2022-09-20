#include<linux/kernel.h>
#include<linux/module.h>
#define E_OK  (0)

static int led_init(void)
{
	printk("led init go\r\n");
	return E_OK;
}

static void led_exit(void)
{
	printk("led exit go \r\n");

}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("chenhaijun");


































