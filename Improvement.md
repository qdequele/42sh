#List of bugs :

##LEAKS

==15266== 76 (64 direct, 12 indirect) bytes in 4 blocks are definitely lost in loss record 51 of 85
==15266==    at 0x10002D671: malloc (in /Users/bjamin/.brew/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15266==    by 0x100006428: assert_argv (parser_argv.c:78)
==15266==    by 0x100006570: parse_cmd_argv (parser_argv.c:101)
==15266==    by 0x100006236: parse_process (main_parser.c:87)
==15266==    by 0x100006170: parse_job (main_parser.c:70)
==15266==    by 0x100006031: token_list_to_job_list (main_parser.c:31)
==15266==    by 0x10000B755: process_input (main.c:26)
==15266==    by 0x10000B7FF: shell_start (main.c:50)
==15266==    by 0x10000B934: main (main.c:88)
==15266==
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


##SIGABORT

##SIGSEGV


##BUGS

- cd ~/Desktop
- History
- echo test2 >>
- cat <<

##INPROVEMENT

- set key -> wrong message
- better message for wrong command
- - pwd ||
- || ls
- pwd &&
- && ls