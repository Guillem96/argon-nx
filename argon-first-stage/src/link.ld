ENTRY(_start)

SECTIONS {
	PROVIDE(__ipl_start = 0x40008000);
	. = __ipl_start;
	.text : {
		*(.text._start);
		*(._boot_cfg);
		*(._ipl_version);
		*(.text*);
	}
	.data : {
		*(.data*);
		*(.rodata*);
	}
	. = ALIGN(0x10);
	__ipl_end = .;
	.bss : {
		__bss_start = .;
		*(COMMON)
		*(.bss*)
		__bss_end = .;
	}
}
