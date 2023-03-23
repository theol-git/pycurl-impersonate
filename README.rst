PycURL -- A Python Interface To The cURL library
================================================

.. image:: https://github.com/pycurl/pycurl/workflows/CI/badge.svg
	   :target: https://github.com/pycurl/pycurl/actions

PycURL is a Python interface to `libcurl`_, the multiprotocol file
transfer library. Similarly to the urllib_ Python module,
PycURL can be used to fetch objects identified by a URL from a Python program.
Beyond simple fetches however PycURL exposes most of the functionality of
libcurl, including:

- Speed - libcurl is very fast and PycURL, being a thin wrapper above
  libcurl, is very fast as well. PycURL `was benchmarked`_ to be several
  times faster than requests_.
- Features including multiple protocol support, SSL, authentication and
  proxy options. PycURL supports most of libcurl's callbacks.
- Multi_ and share_ interfaces.
- Sockets used for network operations, permitting integration of PycURL
  into the application's I/O loop (e.g., using Tornado_).

.. _was benchmarked: http://stackoverflow.com/questions/15461995/python-requests-vs-pycurl-performance
.. _requests: http://python-requests.org/
.. _Multi: https://curl.haxx.se/libcurl/c/libcurl-multi.html
.. _share: https://curl.haxx.se/libcurl/c/libcurl-share.html
.. _Tornado: http://www.tornadoweb.org/

What this fork changes ?
------------
This is a modified version of pycurl that adds access to the extra `impersonate` function defined in curl-impersonate from python. Allowing you to impersonate any browser TLS and headers.

Requirements
------------

- Python 3.5-3.10.
- libcurl 7.19.0 or better.


Installation
------------

Please see `INSTALL.rst`_ for installation instructions. 
.. _INSTALL.rst: http://pycurl.io/docs/latest/install.html

Documentation
-------------

Documentation for the development version of PycURL
is available `here <http://pycurl.io/docs/dev/>`_.

To build documentation from source, run ``make docs``.
Building documentation requires `Sphinx <http://sphinx-doc.org/>`_ to
be installed, as well as pycurl extension module built as docstrings are
extracted from it. Built documentation is stored in ``build/doc``
subdirectory.


Support
-------

For curl-impersonate linked issues, feel free to open a github issue, but I do not know if I will have the time to work on this project in the future.


License
-------

::

    Copyright (C) 2001-2008 by Kjetil Jacobsen <kjetilja at gmail.com>
    Copyright (C) 2001-2008 by Markus F.X.J. Oberhumer <markus at oberhumer.com>
    Copyright (C) 2013-2022 by Oleg Pudeyev <code at olegp.name>

    All rights reserved.

    PycURL is dual licensed under the LGPL and an MIT/X derivative license
    based on the cURL license.  A full copy of the LGPL license is included
    in the file COPYING-LGPL.  A full copy of the MIT/X derivative license is
    included in the file COPYING-MIT.  You can redistribute and/or modify PycURL
    according to the terms of either license.

.. _PycURL: http://pycurl.io/
.. _libcurl: https://curl.haxx.se/libcurl/
.. _urllib: http://docs.python.org/library/urllib.html
.. _`the repository`: https://github.com/pycurl/pycurl
.. _`mailing list`: http://cool.haxx.se/mailman/listinfo/curl-and-python
.. _`downloads repository`: https://github.com/pycurl/downloads
