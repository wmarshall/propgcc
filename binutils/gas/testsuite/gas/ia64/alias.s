	.section .foo,"aw","progbits"
	.secalias .foo,"1234"
	.secalias .foo,"1234"
	.alias foo, "\"\80\84\""
	.alias foo, "\"\80\84\""
foo:
	stringz "\"\80\84\""
	.secalias .foo,"1234"
	.secalias .foo,"1234"
	.alias foo, "\"\80\84\""
	.alias foo, "\"\80\84\""
