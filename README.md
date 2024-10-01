# A simple logger written in C99

<!-- TODO: -->
<!-- ![cover] (addr) -->

## Contents

- [Introduction](#introduction)
- [Overview](#overview)
- [Usage](#usage)
- [TODO](#todo)

## Introduction

Since most of us programmers use print debugging method, having a clean text with time and detail can be pretty helpful.
This tool is built to be very simple and portable since it's written with C99 standard.

## Usage

> There are different levels of logging:

- TRACE
- DEBUG
- INFO
- WARN
- ERROR
- FATAL

> #### Note
>
> For now WARN, ERROR and FATAL are written to `stderr` stream and the rest to `stdout`.

>

> For normal log message use, you can use below macro format:
>
> ```c
> YALOG_DEBUG("Initialized GLFW.");
> ```
>
> Or for formatted strings:
>
> ```c
> YALOG_DEBUG_F("Initialized %s.", "GLFW");
> ```

> #### Use In Your Project
>
> Add the source code in `src/` folder to your project and use the functionality.

## Todo

- [ ] Add user defined streams.
- [ ] Add logging display format manipulation.
