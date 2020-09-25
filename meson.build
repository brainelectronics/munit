# The project will be called munit
project('munit', 'c',
  default_options : ['b_colorout=always']
)

conf_data = configuration_data()
conf_data.set('version', '0.2.0')

add_project_arguments('-std=c99', language : 'c')

cc  = meson.get_compiler('c')

root_include = include_directories('.')

munit = library('munit',
    ['munit.c'],
    install: meson.is_subproject())

if meson.is_subproject()
  munit_dep = declare_dependency(
      include_directories : root_include,
      link_with : munit)
else
  # standalone install
  install_headers('munit.h')

  pkg = import('pkgconfig')
  pkg.generate(name: 'munit',
                description: 'µnit Testing Library for C',
                version: conf_data.get('version'),
                libraries: munit)



  # compile the demo project
  munit_example_src = files('example.c')
  munit_example = executable('example_test',
                             munit_example_src,
                             include_directories: root_include,
                             link_with: munit)
  test('example_test', munit_example)

  # Add a target so it is possible to write ninja "example_test"
  run_target('example_test', command : munit_example)



  # add all files required to compile the calculator test
  munit_calculator_test_src = files('calculator/src/calculator.c',
                                    'calculator/unit_test/calculator-test.c')
  munit_calculator_test = executable('calculator_test',
                                      munit_calculator_test_src,
                                      include_directories: root_include,
                                      link_with: munit)
  test('calculator_test', munit_calculator_test)

  # Add a target so it is possible to write ninja "calculator_test"
  run_target('calculator_test', command : munit_calculator_test)
endif

# add all files required to compile the calculator example
calculator_example_src = files('calculator/src/calculator.c',
                               'calculator/calculator-example.c')
calculator_example = executable('calculator_example',
                                calculator_example_src)

# Add a target so it is possible to write ninja "calculator"
run_target('calculator', command : calculator_example)
