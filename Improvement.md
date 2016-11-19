#List of bugs :

##LEAKS


ls > test1 > test2  | cat -e > test3



5 bytes in 1 blocks are definitely lost in loss record 5 of 114
==99953==    at 0x10002E671: malloc (in /Users/eebersol/.brew/Cellar/valgrind/HEAD-16117/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==99953==    by 0x10000E17C: ft_strdup (ft_strdup.c:28)
==99953==    by 0x100007B35: parse_append_redir (parser_io_channel.c:29)
==99953==    by 0x100007DE3: count_target_length (parser_io_utils.c:44)
==99953==    by 0x100007A0A: parse_io_channel (parser_io_channel.c:47)
==99953==    by 0x10000754C: parse_cmd_argv (parser_argv.c:119)
==99953==    by 0x100007166: parse_process (main_parser.c:87)
==99953==    by 0x1000070A0: parse_job (main_parser.c:70)
==99953==    by 0x100006F61: token_list_to_job_list (main_parser.c:31)
==99953==    by 0x10000C705: process_input (main.c:26)
==99953==    by 0x10000C7AF: shell_start (main.c:50)
==99953==    by 0x10000C8E4: main (main.c:88)
==99953==
==99953== 12 bytes in 2 blocks are definitely lost in loss record 10 of 114
==99953==    at 0x10002E671: malloc (in /Users/eebersol/.brew/Cellar/valgrind/HEAD-16117/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==99953==    by 0x10000E17C: ft_strdup (ft_strdup.c:28)
==99953==    by 0x100007B35: parse_append_redir (parser_io_channel.c:29)
==99953==    by 0x100007DE3: count_target_length (parser_io_utils.c:44)
==99953==    by 0x100007A0A: parse_io_channel (parser_io_channel.c:47)
==99953==    by 0x1000074F3: parse_cmd_argv (parser_argv.c:108)
==99953==    by 0x100007166: parse_process (main_parser.c:87)
==99953==    by 0x1000070A0: parse_job (main_parser.c:70)
==99953==    by 0x100006F61: token_list_to_job_list (main_parser.c:31)
==99953==    by 0x10000C705: process_input (main.c:26)
==99953==    by 0x10000C7AF: shell_start (main.c:50)
==99953==    by 0x10000C8E4: main (main.c:88)

------------------------------------------------------

42sh $> ls | pwd | coucou

==7465== 251 (24 direct, 227 indirect) bytes in 1 blocks are definitely lost in loss record 90 of 121
==7465==    at 0x10002E671: malloc (in /Users/eebersol/.brew/Cellar/valgrind/HEAD-16117/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==7465==    by 0x10000CDCE: ft_lstnew (in ./42sh)
==7465==    by 0x100006BA2: new_token (token_to_list.c:21)
==7465==    by 0x100006A94: cmd_to_token (main_lexer.c:58)
==7465==    by 0x1000069B7: input_to_token_list (main_lexer.c:79)
==7465==    by 0x10000C6D1: process_input (main.c:22)
==7465==    by 0x10000C79F: shell_start (main.c:50)
==7465==    by 0x10000C8D4: main (main.c:88)




##SIGABORT

##SIGSEGV

##BUGS

##INPROVEMENT

- set key -> wrong message
- better message for wrong command