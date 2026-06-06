# vcs-cli

*vcs-cli* is a git clone intended for use for only one individual with basic version control needs.  
It can make and reverse commits as well as name them but not much else.  
It's good enough for use on small projects.

# Installation:
Run the following commands to build and install the program:

```bash
sudo cmake -Bcmake-build-debug -H.
sudo cmake --build cmake-build-debug --target install
```

### Usage:
Make a new repository:
````
vcs-cli init
````

Make a new commit:
````
vcs-cli new
````

Revert a commit:
````
vcs-cli revert 000X
````
This command will revert all commits back to the version before the specified commit was made.  

Note: "000X" should be replaced with the number of the commit/patch you want to revert to.  
The zeroes are optional. "vcs-cli revert 00001" and "vcs-cli revert 1" are the same in the eyes of the program.