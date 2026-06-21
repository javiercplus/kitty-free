/*
 * systemd.c
 * Copyright (C) 2024 Kovid Goyal <kovid at kovidgoyal.net>
 *
 * Distributed under terms of the GPL3 license.
 *
 * systemd dependency removed for non-systemd init systems (runit, openrc, etc.)
 */

#include "data-types.h"

static PyObject*
systemd_move_pid_into_new_scope(PyObject *self UNUSED, PyObject *args UNUSED) {
    PyErr_SetString(PyExc_NotImplementedError, "systemd support is not available in this build");
    return NULL;
}

static PyMethodDef module_methods[] = {
    METHODB(systemd_move_pid_into_new_scope, METH_VARARGS),
    {NULL, NULL, 0, NULL}
};

bool
init_systemd_module(PyObject *module) {
    if (PyModule_AddFunctions(module, module_methods) != 0) return false;
    return true;
}
