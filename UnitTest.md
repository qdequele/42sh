# Unit test

## Builtins

###bg

```
- bg
- bg (good_pid)
- bg (wrong_pid)
```

###cd

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

### echo

```
- echo 
- echo test1 test2
- echo ""
- echo ''
- echo $HOME '$HOME' $HOME
- echo $HOME '$HOME ' $HOME
- echo $HOME ' $HOME' $HOME
- echo $HOME ' $HOME ' $HOME
- echo $HOME' $HOME '$HOME
- echo $HOME'$HOME '$HOME
- echo $HOME' $HOME'$HOME
- echo $HOME'$HOME'$HOME
- echo $HOME'$HOME ?'$HOME
- echo $HOME'$HOME?'$HOME
- echo $HOME'
	$HOME'
- echo $HOME'
	$HOME
	'
```

###env

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

###exit

```
- exit
- exit 0
- exit 5
```

###export

```
- export
- export unset_key
- set key val ; export key
```

###fg

```
- fg
- fg (good_pid)
- fg (wrong_pid)
```

###help

```
- help
```

###history

```
- history (when no command has been exec)
- history (when some commands has been exec)
```

###jobs

```
- jobs
```

###read

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

###readonly

```
- readonly
- readonly unset_key
- readonly key
- readonly already_set_key
```

###set

```
- set
- set key
- set key value
- set key value value2
- set _key value
- set key2 value
- set key_2 value
```

###setenv

```
- setenv
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

###unreadonly

```
- unreadonly
- unreadonly unset_key
- unreadonly key
- unreadonly already_set_key
```

###unset

```
- unset
- unset key
- unset unexisting_key
- unset key key_
```

###unsetenv

```
- unsetenv
- unsetenv key
- unsetenv unexisting_key
- unsetenv key key_
```

### !

```
- !
- ![good index]
- ![wrong index]
- ![good cmd]
- ![wrong cmd]
- ![index]
- ![cmd]
- ![wromg cmd]
```
## command

### Semi colon

```
- ;
- ls ; pwd
- ls;pwd
- ls ;
- ; ls
- cat ; ls
```

### Or

```
- true || ls
- false || ls
- pwd || ls
- pwd ||
- || ls
```

### AND

```
- true && ls
- false && ls
- pwd && ls
- pwd &&
- && ls
```

### Pipe

```
- ls | cat -e
- ls | sort -r | cat -e
- base64 /dev/random | head -c 1000 | grep 42 | wc -l | sed -e 's/1/YES/g' -e 's/0/NO/g'
- cat | cat -e
```

### Redirection

```
- ls > test
- ls toto > test
- pwd > test > test2 > test3
- ls toto 2>&1 test
- ls toto 1>&2 test
- ls libft 1>&2 test
- ls libft 2>&1 test
- ls libft 1>&-
- ls libft 2>&-
- ls val 1>&-
- ls val 2>&-
- cat < echo test
- echo test1 >> test
- echo test2 >> test
- echo test2 >>
```

### Heredoc

```
- cat << EOF
- cat << test
- cat <<
```

### background mode

```
- ls &
- ping google.com &
- ping google.com 1>&- &
- base64 /dev/random | head -c 1000 | grep 42 | wc -l | sed -e 's/1/YES/g' -e 's/0/NO/g' &
```

## Shortcut

### ctrl + d

```
- kjfjdfkas (ctrl + d) -> nothing happen
- (ctrl + d) -> shell quit
```

### ctrl + c

```
- cat (ctrl + c) -> quit cat
- (ctrl + c) -> nothing happen
```
