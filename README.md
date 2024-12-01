# kernel_linked_list

# Description: 
		The purpose of this program is to create a linked list and 
		load it with four struct color elements. Once loaded, we traverse
	    linked list and output its contents to the kernel log buffer.
		In the exitpoint, we delete the elements from the list and return
	    the free memory back to the kernel.

# To compile: 

        gcc kernel_linked_list.c -o kll


# To execute: 
    
        ./kll
