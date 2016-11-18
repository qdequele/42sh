#List of bugs :

##LEAKS

Should be resolved: - Leaks on command not found
impossible to reproduce: - Leaks when PATH incorect and execute ls

# Errors read (is malloc?)

- Read on $test when test is unset
- Read on setenv PWD [val] -> (env.46) env_get + (prompt_length.c:21) get_current_folder
- Read on set (vars.c:42)

##SIGABORT

- SIGABRT on unsetenv
- SIGABRT on unsetenv PWD value

##SIGSEGV


##BUGS

- FIX space between quotes will not disapear

##INPROVEMENT

- set key -> wrong message
- better message for wrong command
