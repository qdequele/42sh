#List of bugs :

##LEAKS

- Leaks on command not found
- Leaks on set (vars.c:42)
- Leaks on setenv PWD [val] -> (env.46) env_get + (prompt_length.c:21) get_current_folder
- Leaks when PATH incorect and execute ls
- Leaks on (test1 || ls || test2)
- Leaks on $test when test is unset
- Leaks on (set key val ; export key)

##SIGABORT

- SIGABRT on unsetenv
- SIGABRT on unsetenv PWD value

##SIGSEGV


##BUGS

- FIX space between quotes will not disapear

##INPROVEMENT

- set key -> wrong message
- better message for wrong command
