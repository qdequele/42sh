#List of Leaks :

- Leaks on command not found
- Leaks on set (vars.c:42)
- Leaks on read [key1]-[val1 val2 val3] -> invalid free (vars.87) var add or modify
- Leaks on read [ ]-[val1] -> invalid read (read.19) more_key_than_value
- Leaks on setenv PWD [val] -> (env.46) env_get + (prompt_length.c:21) get_current_folder
- Leaks when PATH incorect and execute ls

# List of bugs
Redirection : pwd >> test2 && ls eeweweq 2>&1 | cat -e

- Met deux fois pwd dans test2

unsetenv soething -> leaks
setenv dsd sdsdsd + env -> leaks



echo to                    to 'to                         to' "to                            to" 

result -> ti ti to to to to
expected ti ti to    to to    to



42sh $> toto || ls || titi -> leaks (surement parcequ'il test titi);