# µnit

µnit is a small but full-featured unit testing framework for C.  It has
no dependencies (beyond libc), is permissively licensed (MIT), and is
easy to include into any project.

For more information, see
[the µnit web site](https://nemequ.github.io/munit).

[![Build status](https://travis-ci.org/nemequ/munit.svg?branch=master)](https://travis-ci.org/nemequ/munit)
[![Windows build status](https://ci.appveyor.com/api/projects/status/db515g5ifcwjohq7/branch/master?svg=true)](https://ci.appveyor.com/project/quixdb/munit/branch/master)

## Features

Features µnit currently includes include:

 * Handy assertion macros which make for nice error messages.
 * Reproducible cross-platform random number generation, including
   support for supplying a seed via CLI.
 * Timing of both wall-clock and CPU time.
 * Parameterized tests.
 * Nested test suites.
 * Flexible CLI.
 * Forking
   ([except on Windows](https://github.com/nemequ/munit/issues/2)).
 * Hiding output of successful tests.

Features µnit does not currently include, but some day may include
(a.k.a., if you file a PR…), include:

 * [TAP](http://testanything.org/) support; feel free to discuss in
   [issue #1](https://github.com/nemequ/munit/issues/1)

### Include into your project with meson

In your `subprojects` folder put a `munit.wrap` file containing:

```
[wrap-git]
directory=munit
url=https://github.com/nemequ/munit/
revision=head
```

Then you can use a subproject fallback when you include munit as a
dependency to your project: `dependency('munit', fallback: ['munit', 'munit_dep'])`

## Getting started

### Clone this repo

```bash
cd some/directory
git clone https://github.com/nemequ/munit.git
```

### Install meson and ninja

This will create a virtual environment, so you don't touch your local
modules of python

```bash
python3 -m venv my_virtual_env
source my_virtual_env/Scripts/active
pip install -r requirements.txt
```

In case you encounter an issue during the Python package installation due to a
[SSL certificate verification error](https://stackoverflow.com/questions/25981703/pip-install-fails-with-connection-error-ssl-certificate-verify-failed-certi)
add the `--trusted-host` option to the pip command.

```bash
pip install -r requirements.txt --trusted-host pypi.org --trusted-host files.pythonhosted.org
```

To leave the virtual env simply close the Bash or call `deactivate`.

Test the installation of meson and ninja

```bash
meson --version
ninja --version
```

### Compile and test

These steps will create a build directory and run some examples, refer to the
comments of each command

```bash
# setup a new build directory called "builddir"
meson builddir --layout flat --buildtype plain

# compile everything (tests, examples, ...)
ninja -C builddir

# run all unit tests at once
ninja -C builddir test

# run the example test only
ninja -C builddir example_test

# run the calculator test only
ninja -C builddir calculator_test

# run the calculator example
ninja -C builddir calculator
```

## Documentation

See [the µnit web site](https://nemequ.github.io/munit).

Additionally, there is a heavily-commented
[example.c](https://github.com/nemequ/munit/blob/master/example.c) in
the repository.
