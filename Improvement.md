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

## Read

42sh $> git add s==26460== Invalid read of size 1
==26460==    at 0x10000E698: ft_strlen (ft_strlen.c:20)
==26460==    by 0x10000ACAE: sort_by_lexycography (clean.c:83)
==26460==    by 0x10000D0B5: ft_lst_bubble_sort (ft_lstsort.c:29)
==26460==    by 0x10000995A: set_possibilities (autocomplete.c:30)
==26460==    by 0x100009871: action_autocomplete (autocomplete.c:78)
==26460==    by 0x10000BF33: prompt_find_function (find.c:98)
==26460==    by 0x100009E77: read_normal_input (read.c:33)
==26460==    by 0x10000C765: shell_start (main.c:44)
==26460==    by 0x10000C8D4: main (main.c:88)
==26460==  Address 0x100b86666 is 0 bytes after a block of size 6 alloc'd
==26460==    at 0x10002E671: malloc (in /Users/bjamin/.brew/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==26460==    by 0x10000CE19: ft_lstnew (ft_lstnew.c:28)
==26460==    by 0x10000BBDF: get_builtins_list (get_possibilities.c:47)
==26460==    by 0x10000990D: set_possibilities (autocomplete.c:26)
==26460==    by 0x100009871: action_autocomplete (autocomplete.c:78)
==26460==    by 0x10000BF33: prompt_find_function (find.c:98)
==26460==    by 0x100009E77: read_normal_input (read.c:33)
==26460==    by 0x10000C765: shell_start (main.c:44)
==26460==    by 0x10000C8D4: main (main.c:88)
==26460==
==26460== Invalid read of size 1
==26460==    at 0x10000E698: ft_strlen (ft_strlen.c:20)
==26460==    by 0x10000AC9E: sort_by_lexycography (clean.c:82)
==26460==    by 0x10000D0B5: ft_lst_bubble_sort (ft_lstsort.c:29)
==26460==    by 0x10000995A: set_possibilities (autocomplete.c:30)
==26460==    by 0x100009871: action_autocomplete (autocomplete.c:78)
==26460==    by 0x10000BF33: prompt_find_function (find.c:98)
==26460==    by 0x100009E77: read_normal_input (read.c:33)
==26460==    by 0x10000C765: shell_start (main.c:44)
==26460==    by 0x10000C8D4: main (main.c:88)
==26460==  Address 0x100b86666 is 0 bytes after a block of size 6 alloc'd
==26460==    at 0x10002E671: malloc (in /Users/bjamin/.brew/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==26460==    by 0x10000CE19: ft_lstnew (ft_lstnew.c:28)
==26460==    by 0x10000BBDF: get_builtins_list (get_possibilities.c:47)
==26460==    by 0x10000990D: set_possibilities (autocomplete.c:26)
==26460==    by 0x100009871: action_autocomplete (autocomplete.c:78)
==26460==    by 0x10000BF33: prompt_find_function (find.c:98)
==26460==    by 0x100009E77: read_normal_input (read.c:33)
==26460==    by 0x10000C765: shell_start (main.c:44)
==26460==    by 0x10000C8D4: main (main.c:88)

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