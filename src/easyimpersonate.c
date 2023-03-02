#include "pycurl.h"

static PyObject *
do_curl_impersonate_impl(CurlObject *self, PyObject *target, int default_headers)
{
    char *str = NULL;
    PyObject *encoded_obj;
    int res;

    str = PyText_AsString_NoNUL(target, &encoded_obj);
    if (str == NULL)
        return NULL;

    /* Call setopt */
    res = curl_easy_impersonate(self->handle, str, default_headers);
    /* Check for errors */
    if (res != CURLE_OK)
    {
        PyText_EncodedDecref(encoded_obj);
        CURLERROR_RETVAL();
    }
    PyText_EncodedDecref(encoded_obj);
    Py_RETURN_NONE;
}

PYCURL_INTERNAL PyObject *
do_curl_impersonate(CurlObject *self, PyObject *args)
{
    PyObject *target;
    int default_headers;

    if (!PyArg_ParseTuple(args, "Oi:impersonate", &target, &default_headers))
        return NULL;
    if (check_curl_state(self, 1 | 2, "impersonate") != 0)
        return NULL;

    if (PyText_Check(target))
    {
        return do_curl_impersonate_impl(self, target, default_headers);
    }

    /* Failed to match any of the function signatures -- return error */
    PyErr_SetString(PyExc_TypeError, "invalid arguments to impersonate");
    return NULL;
}
