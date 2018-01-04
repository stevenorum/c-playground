# general_intro

## Random syntactic notes

In some places I'll embed shell sessions for illustrative purposes.
Lines beginning with ```%``` show the commands being run.
The lines between those is the output.
I'll usually (but possibly not always) end blocks with a blank ```%``` line to make extra-clear that's the end. 

```Shell
% ls
README.md	general_intro	makefiles_intro	notes.txt	notes.txt~	really_basic_c
% git status
On branch master
Your branch is up-to-date with 'origin/master'.

nothing to commit, working tree clean
% git log -n 1
commit 748df2604d6a4db7b497c3bb9e96b3fb2e7b6745 (HEAD -> master, origin/master, origin/HEAD)
Author: Steve Norum <stevenorum@gmail.com>
Date:   Thu Jan 4 14:10:50 2018 -0500

    01makefiles_intro to makefiles_intro
% 
```

When I have a block of shell code that it may be useful to be copy-paste and run, it won't have the ```%``` prefixes and any comments or expected outputs will be commented by ```#```.

I may or may not indicate for each comment whether it's a comment, expected stdout, expected stderr, or expected exit code.

Here's a fairly convoluted example:

```Shell
mkdir -p test_directory
touch test_directory/Im_a_file
# (comment) The following command will fail because the directory has contents
rmdir test_directory
# (stderr) rmdir: test_directory: Directory not empty
# (exit code) 1
ls test_directory/
# (stdout) Im_a_file
rm test_directory/Im_a_file
ls test_directory
# (no stdout expected)
# (exit code) 0
rmdir test_directory
ls test_directory
# (stderr) ls: test_directory: No such file or directory
# (exit code) 1
mkdir -p test_directory
touch test_directory/Im_a_file
ls test_directory
# (stdout) Im_a_file
rm -rf test_directory/
ls test_directory
# ls: test_directory: No such file or directory
```
