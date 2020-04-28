# NADI

A simple, generic service provider interface to get and set key-value pairs in named dictionaries.  

The low level C interface facilitates cross-platform ports and various language bindings.

The provider architecture allows delegation of how values are retrieved to an independent component, so that access control and storage can be chosen at deployment time or runtime. This enables implementation of any sharing and security policies.

## Concepts

* a dictionary is a collection of key-value pairs, where keys are unique
* a dictionary can have a default key
* the provider may support a single default dictionary and/or multiple named dictionaries
* providers may implement either or both of 2 functions:
   * **get** to retrieve a value from a dictionary
   * **put** to store a value into a dictionary

## Design

The C-language NADI provider SPI defines one type and 2 functions:
* the *named dictionary request* type (**nd_req_t**)
* the **nd_req_t nd_get(nd_req_t)** function
* the **nd_req_t nd_put(nd_req_t)** function

The core library also provides functions to manage requests
* nd_req_t nd_alloc()
* nd_free(nd_req_t)
* nd_req_t nd_set_...(nd_req_t, ...)

## Samples and Demo

### Build

To build the samples:
* run **setup** to set the Makefile according to your OS (Linux or Darwin)
* run **make providers** to build the sample providers
* run **make demo** to build the demo program

### Demo

The **demo** program takes a variable name as an argument (example: demo COLOR) and displays the corresponding value.
