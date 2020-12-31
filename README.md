# c-practice
Repository containing basic C projects for unit testing, command line parsing, etc.

## Requirements
 - GNU make
 - gcc
 - cunit
 - check
 
## Building
```sh
make
```
 
## Running tests
```sh
make test
```

# Install commit hook
```sh
ln -s $(pwd)/hooks/pre-commit-hook.sh .git/hooks/pre-commit && chmod +x .git/hooks/pre-commit
```
