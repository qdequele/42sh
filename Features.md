#Features :

X : Todo
O : Done
F : Need Fix
I : Impossible
L : Leaks

prototype : - X : blabla (username)

##Line Edition

###Mandatory

- O : Show prompt
- O : add one char
- O : del one char
- O : move to left
- O : move to right
- O : History
- O : Copy/Past/Cut
- O : move word left alt+left
- O : move word right alt+right
- O : move start fn+left | home
- O : move end fn+right | end
- O : move up alt+up
- O : move down alt+down
- O : quotes " ' ` ()
- O : Good implementation of tab or spaces

###Bonus

- O : history search builtins history | ctrl+R
- O : autocomplete
- O : Move max top
- O : Move max bottom
- O : Operator || and &&

##Command execution

###Mandatory

- O : Line separator ;
- O : pipes |
- O : redirect  < >> >
- O : file descriptor agregator 2>&-
- O : Catch execution return number $?
- O : Logic operation || &&
- O : ctrl+c didn't quit the shell
- O : double ctrl+d quit the shell

###Bonus

- O : heredoc <<
- O : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash)
- O : local varaibles unset export $
- L : Job controls job / fg / bg / &

##Builtins

###Mandatory

- O : cd
- O : echo
- O : exit
- O : env
- O : setenv
- O : unsetenv
- O : set
- O : unset
- O : export
- O : readonly
- O : unreadonly

###Bonus

- O : History
- O : Read

##General

- X : Leaks
- O : Norme
- X : Segfaut
- O : Signals
- X : Builtins Posix







#Liste des Leaks :

- Leaks on command not found
- Leaks on set (vars.c:42)
- Leaks on read [key1]-[val1 val2 val3] -> invalid free (vars.87) var add or modify
- Leaks on read [ ]-[val1] -> invalid read (read.19) more_key_than_value
- Leaks on setenv PWD [val] -> (env.46) env_get + (prompt_length.c:21) get_current_folder
- Leaks when PATH incorect and execute ls












# Unit test

##env

```
- env key=value
- env -i
- env -i env
- env -i key=value key2=value2 env
- env -i key=value
- env ./21sh
- env -i ./21sh
- env -i PATH= ./21sh
- env -i TERM=xterm-256color ./21sh
- env -i PATH=/usr/bin ./21sh
- env -i PATH= TERM=xterm-256color ./21sh
```

##setenv

```
- setenv key val
- setenv _key val
- setenv key_ val
- setenv key1 val
- setenv key val value
- setenv PATH
- setenv PATH /
- setenv PATH /usr/bin
- setenv PWD /
- setenv PWD blabla
```

##unsetenv

```
- unsetenv key
- unsetenv key key_

```

##read

```
- read test1
 	Read> test2
- read test1 test2
 	Read> test3
- read test1 
 	Read> test2 test3 
- read
	Read>
- read test
	Read>
- read
	Read> test
```

##cd

```
- cd ..
- cd .
- cd ~
- cd -
- cd (dir)
- cd /(dir)
- cd ~/(dir)
- cd (tab)
```

##history

```
- history (when no command has been exec)
- history (when some commands has been exec)
```

## !

```
- !
- ![good index]
- ![wrong index]
- ![good cmd]
- ![wrong cmd]
- ![index]
```

## ctrl + d

```
- kjfjdfkas (ctrl + d) -> nothing happen
- (ctrl + d) -> shell quit
```

## ctrl + c

```
- cat (ctrl + c) -> quit cat
- (ctrl + c) -> nothing happen
```



Redirection : pwd >> test2 && ls eeweweq 2>&1 | cat -e

- Met deux fois pwd dans test2

unsetenv soething -> leaks
setenv dsd sdsdsd + env -> leaks



echo to                    to 'to                         to' "to                            to" 

result -> ti ti to to to to
expected ti ti to    to to    to



42sh $> toto || ls || titi -> leaks (surement parcequ'il test titi);