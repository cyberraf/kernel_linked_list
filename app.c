#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>

struct color {
    int red;
    int green;
    int blue;
    struct list_head list;
};

static LIST_HEAD(color_list); //Declares and initializes the variable color_list of type struct list_head

static int __init my_module_init(void)
{
	//Creating an instance or object of struct color 
    	struct color *mycolor;
	mycolor = kmalloc(sizeof(struct color), GFP_KERNEL); //kmalloc() allocates memory
							     //GFP_KERNEL indicates the routine
							     //kernel memory allocation
    	mycolor->red = 30;
    	mycolor->green = 160;
    	mycolor->blue = 970;
    	INIT_LIST_HEAD(&c->list); 			    //Initializing the list member in struct color
    	
	list_add_tail(&mycolor->list, &color_list);         //Adding the instance to the end of the linked
       							    //list

	//printing out the content of the linked list by traversing it
    	struct color *ptr;
    	printk(KERN_INFO "Linked List Contents:\n");

    	list_for_each_entry(ptr, &color_list, list) {
        	printk(KERN_INFO "Red: %d Green: %d Blue: %d\n", ptr->red, ptr->green, ptr->blue);
    	}

    	return 0;
}

static void __exit my_module_exit(void)
{
	list_del(struct list_head *element);

    	struct color *ptr, *next;

    	list_for_each_entry_safe(ptr, next, &color_list, list) {
        	list_del(&ptr->list); //deleting the list
        	kfree(ptr);
    	}
    	printk(KERN_INFO "Linked List Deleted.\n");
}

module_init(my_module_init); //initializing and traversing the linked list
module_exit(my_module_exit); //Deleting the list
MODULE_LICENSE("RT,CH");

