# c-practice
Repository containing basic C projects for unit testing, command line parsing, etc.

## Requirements
 - GNU make
 - gcc
 - cunit
 - check
 
## Make targets

*Check* Runs tests for each sub-project.
```sh
make check
```

*Benchmark* Executes benchmark tests for each sub-project.
```sh
make benchmark
```

*Profile* Generate gprof reports.
```sh
make profile
```

*Debug* Generate gdb debug objects.
```sh
make debug
```

## Contributing

### Install commit hook
Enable git hook to run test for each commit:
```sh
ln -s $(pwd)/hooks/pre-commit-hook.sh .git/hooks/pre-commit && chmod +x .git/hooks/pre-commit
```
