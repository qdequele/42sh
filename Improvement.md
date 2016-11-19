#List of bugs :

##LEAKS


------------------------------------------------------

42sh $> ls || pwd || cat -efd jdsa kfhsdlf isadhfsad;fsdf jsad

==99520== 51 (40 direct, 11 indirect) bytes in 2 blocks are definitely lost in loss record 46 of 116
==99520==    at 0x10002E671: malloc (in /Users/eebersol/.brew/Cellar/valgrind/HEAD-16117/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==99520==    by 0x100007358: assert_argv (parser_argv.c:78)
==99520==    by 0x1000074A0: parse_cmd_argv (parser_argv.c:101)
==99520==    by 0x100007166: parse_process (main_parser.c:87)
==99520==    by 0x1000070A0: parse_job (main_parser.c:70)
==99520==    by 0x100006F61: token_list_to_job_list (main_parser.c:31)
==99520==    by 0x10000C705: process_input (main.c:26)
==99520==    by 0x10000C7AF: shell_start (main.c:50)
==99520==    by 0x10000C8E4: main (main.c:88)


When exit :


==99481== 151 (104 direct, 47 indirect) bytes in 4 blocks are definitely lost in loss record 52 of 79
==99481==    at 0x10002E671: malloc (in /Users/eebersol/.brew/Cellar/valgrind/HEAD-16117/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==99481==    by 0x100007358: assert_argv (parser_argv.c:78)
==99481==    by 0x1000074A0: parse_cmd_argv (parser_argv.c:101)
==99481==    by 0x100007166: parse_process (main_parser.c:87)
==99481==    by 0x1000070A0: parse_job (main_parser.c:70)
==99481==    by 0x100006F61: token_list_to_job_list (main_parser.c:31)
==99481==    by 0x10000C705: process_input (main.c:26)
==99481==    by 0x10000C7AF: shell_start (main.c:50)
==99481==    by 0x10000C8E4: main (main.c:88)

------------------------------------------------------

ls >> sdas dasd >> dasdas D<da dasd asd asdsf||d sadas d|| fdfs cat2 :



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


##SIGABORT

##SIGSEGV

##BUGS

##INPROVEMENT

- set key -> wrong message
- better message for wrong command