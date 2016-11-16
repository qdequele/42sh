#List of bugs :

##LEAKS

- Leaks on command not found
- Leaks on set (vars.c:42)
- Leaks on read [key1]-[val1 val2 val3] -> invalid free (vars.87) var add or modify
- Leaks on read [ ]-[val1] -> invalid read (read.19) more_key_than_value
- Leaks on setenv PWD [val] -> (env.46) env_get + (prompt_length.c:21) get_current_folder
- Leaks when PATH incorect and execute ls
- Leaks on (test1 || ls || test2)
- Leaks on $test when test is unset
- Leaks on (set key val ; export key)

##SIGABORT

- SIGABRT on unsetenv
- SIGABRT on unsetenv PWD value
- SIGABRT on reset value with read

##SIGSEGV

- SEGSEGV read
			Read> test

##BUGS

- FIX space between quotes will not disapear
- FIX read test1 test2
		Read>test3 test3 -> not have good values
- FIX read make insane job

##INPROVEMENT

- set key -> wrong message
- better message for wrong command
