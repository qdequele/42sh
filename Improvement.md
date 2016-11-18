#List of bugs :

##LEAKS

==15266== 170 (48 direct, 122 indirect) bytes in 2 blocks are definitely lost in loss record 59 of 85
==15266==    at 0x10002D671: malloc (in /Users/bjamin/.brew/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15266==    by 0x10000BE2E: ft_lstnew (in ./42sh)
==15266==    by 0x100005CB2: new_token (token_to_list.c:21)
==15266==    by 0x100005BA4: cmd_to_token (main_lexer.c:58)
==15266==    by 0x100005AC7: input_to_token_list (main_lexer.c:79)
==15266==    by 0x10000B731: process_input (main.c:22)
==15266==    by 0x10000B7FF: shell_start (main.c:50)
==15266==    by 0x10000B934: main (main.c:88)
==15266==

## Read

##SIGABORT

##SIGSEGV

##BUGS

##INPROVEMENT

- set key -> wrong message
- better message for wrong command
- - pwd ||
- || ls
- pwd &&
- && ls