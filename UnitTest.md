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