# Git Cheatsheet

## Before edit repo

### Cloning a repo to your local
```
git clone
```

### Make sure you have latest commit version of remote
```
git pull
```
Please do this everytime before edit any file.

### Check your local status compare to last pull
```
git status
```
Very useful to check your local changes.

## Before pushing to remote(Github)

### Check your local status compare to last pull
```
git status
```
As previously described.

### Add the file you want to commit
```
git add
```
After changing a file and enter `git status`, the file can be added.

### Commit the changed file 
```
git commit (-m "brief description about your changing")
```
You can commit multiple files at the same time, but for big modification we prefer commit only one file or in even modify in multiple commits.
It's better to make it easier to understand why and how you edit the codes and write a clear description.

### Push to remote(Github)
```
git push
```
**Be aware of merge conflict**
If you didn't following the instruction or something else went wrong, it is possible to cause some merge conflict.
If any merge conflict occurs, you may not push files. **Don't try to force it**, or it could break the code. Sometimes it's hard to recover.

## Handle merge conflict
### possible solutions
1. back up the local files then remove the entire directory 
2. make a new repo
3. literlly deal with merge conflict one by one (time comsuming and easliy fail)





