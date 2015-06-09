[![Build Status](https://travis-ci.org/azriel91/sl_core_application.svg?branch=master)](https://travis-ci.org/azriel91/sl_cmake) [![Build Status](https://webapi.biicode.com/v1/badges/azriel/azriel/sl_core_application/master)](https://www.biicode.com/azriel/sl_core_application)

## sl\_core\_application

This block provides the logic for an application that uses `Activity` classes to provide the application flow.

For a simple application with a single activity, the application terminates when that activity ends. Multiple activities
can be passed in through the activity stack to achieve a linear workflow. More complex workflows can be achieved by
stacking additional activities over an existing activity or replacing an existing activity with another.

There are a few ways to pass information between activities.

* For any two activities that exist on the stack, the writing activity should persist the state externally through a
  service, and the reading activity requests for the information from that service
* For an activity that ends with a replacement / stacked activity, the initial activity may pass through all relevant
  information to the next activity
* For a stacked activity to pass information back to its parent activity, the parent activity may pass an object that
  the stacked activity populates, that the parent activity reads off when the stacked activity ends

## Development

This is implemented as a [CppMicroServices](https://github.com/saschazelzer/CppMicroServices) module, and is built using
[biicode](https://www.biicode.com/).

### Requirements

* [biicode](https://www.biicode.com/downloads)
* [CMake](http://www.cmake.org/install/)
* [g++ 4.8](https://gcc.gnu.org/)

### Building

After cloning, in the repository directory run the following to initialize this as a biicode block:

	bii init -l

Depending on whether you wish to build the block as a static or dynamic CppMicroServices module, run configure with the `BUILD_SHARED_LIBS` flag set to `OFF` or `ON`. If you leave the flag out, it defaults to `OFF`.

	bii configure -DBUILD_SHARED_LIBS=ON

Finally to build the library and test executable, run:

	bii build

The test executable will be output as `bin/azriel_sl_core_application_test_main`.

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
