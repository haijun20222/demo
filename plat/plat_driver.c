plat_probe#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/platform_device.h>
#include<linux/of.h>
struct resource *res1
struct resource *res2;


int plat_probe  (struct platform_device *pdev)
{
	printf("match ok,plat_probe go \n");
	res1 = platform_get_resource(pdev,IORESOURCE_MEM,0);
	if(res1 == NULL)
	{
        	printk("rea1 platform_get_resource fail\n");
	       return -ENOANO;
	}
	printk("res1->start =%llx\n",res1->start);

	res2= platform_get_resource(pdev,IORESOURCE_MEM,0);
	if(res2 == NULL)
	{
        	printk("rea1 platform_get_resource fail\n");
	       return -ENOANO;
	}
	printk("res2->start =%llx\n",res1->start);
	return 0;
}

int  plat_remove(struct platform_device *)
{
	printk("plat_remove go \n");
	return 0;
}

const struct of_device_id	of_plat_match[]={
	{ .compatible = "chj-plat ",},
	{},
};

MODULE_DEVICE_TABLE(of,of_plat_match);

static struct platform_driver plat_driver = {
	.driver = {
			.name = "chj plat driver",
			.ower = THIS_MODULE,
			.of_match_table = of_plat_match,
	}, 
	.probe = plat_probe,
	.remove = plat_remove,
};
modue_platform_driver(plat_driver);

