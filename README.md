# c-practice
Repository containing basic C projects for unit testing, command line parsing, etc.

## Requirements
 - GNU make
 - gcc
 - cunit
 - check
 
## Building
 ´make´
 
## Running tests
 ´make test´

# Install commit hook
´´´
ln -s $(pwd)/hooks/pre-commit-hook.sh .git/hooks/pre-commit && chmod +x .git/hooks/pre-commit
´´´
