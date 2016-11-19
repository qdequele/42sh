#List of bugs :

##LEAKS

-ls > test1 > test2  | cat -e > test3

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


##SIGABORT

##SIGSEGV

##BUGS

##INPROVEMENT

- set key -> wrong message
- better message for wrong command