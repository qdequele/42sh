#List of bugs :

##LEAKS


cat << test




==3774== 24 bytes in 1 blocks are definitely lost in loss record 18 of 78
==3774==    at 0x10002E671: malloc (in /Users/bjamin/.brew/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==3774==    by 0x10000CC8E: ft_lstnew (ft_lstnew.c:19)
==3774==    by 0x100008387: add_to_list (parser_io_channel_heredoc.c:22)
==3774==    by 0x100008194: read_heredoc (parser_io_channel_heredoc.c:72)
==3774==    by 0x100007FFE: parse_heredoc_redir (parser_io_channel_heredoc.c:95)
==3774==    by 0x100007CE3: count_target_length (parser_io_utils.c:44)
==3774==    by 0x1000078B6: parse_io_channel (parser_io_channel.c:57)
==3774==    by 0x100007393: parse_cmd_argv (parser_argv.c:107)
==3774==    by 0x100007006: parse_process (main_parser.c:87)
==3774==    by 0x100006EE1: parse_job (main_parser.c:64)
==3774==    by 0x100006E01: token_list_to_job_list (main_parser.c:31)
==3774==    by 0x10000C5A5: process_input (main.c:26)
==3774==

##SIGABORT

##SIGSEGV

##BUGS

- Issue with cd not showing the right path in prompt: cd /bin or cd ~/Desktop

##INPROVEMENT

- set key -> wrong message
- better message for wrong command