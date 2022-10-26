#include <Python.h>
#include "solpos00.h"

static PyObject *_solpos(PyObject *self, PyObject *args, PyObject *kwargs)
{
    float longitude, latitude, timezone, aspect, press, sbwid, sbrad, sbsky, solcon, temp, tilt;
    int year, month, day, hour, minute, second, interval;

    static char *kwlist[] = {
        "year",
        "month",
        "day",
        "hour",
        "minute",
        "second",
        "timezone",
        "interval",
        "latitude",
        "longitude",
        "aspect",
        "press",
        "sbwid",
        "sbrad",
        "sbsky",
        "solcon",
        "temp",
        "tilt",
        NULL,
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "iiiiiififfffffffff", kwlist, &year, &month,
                                     &day, &hour, &minute, &second, &timezone, &interval,
                                     &latitude, &longitude, &aspect, &press, &sbwid, &sbrad,
                                     &sbsky, &solcon, &temp, &tilt))
        return NULL;

    struct posdata pd, *pdat;
    pdat = &pd;
    S_init(pdat);

    pdat->function = ~S_DOY;

    pdat->year = year;
    pdat->month = month;
    pdat->day = day;
    pdat->hour = hour;
    pdat->minute = minute;
    pdat->second = second;
    pdat->timezone = timezone;
    pdat->interval = interval;
    pdat->latitude = latitude;
    pdat->longitude = longitude;
    pdat->aspect = aspect;
    pdat->press = press;
    pdat->sbwid = sbwid;
    pdat->sbrad = sbrad;
    pdat->sbsky = sbsky;
    pdat->solcon = solcon;
    pdat->temp = temp;
    pdat->tilt = tilt;

    long retval = S_solpos(pdat);

    return Py_BuildValue("{s:i,s:i,s:i,s:i,s:i,s:i,s:f,s:i,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f,s:f}",
                         "year", pdat->year,
                         "month", pdat->month,
                         "day", pdat->day,
                         "hour", pdat->hour,
                         "minute", pdat->minute,
                         "second", pdat->second,
                         "timezone", pdat->timezone,
                         "interval", pdat->interval,
                         "latitude", pdat->latitude,
                         "longitude", pdat->longitude,
                         "amass", pdat->amass,
                         "ampress", pdat->ampress,
                         "aspect", pdat->aspect,
                         "azim", pdat->azim,
                         "cosinc", pdat->cosinc,
                         "coszen", pdat->coszen,
                         "dayang", pdat->dayang,
                         "declin", pdat->declin,
                         "eclong", pdat->eclong,
                         "ecobli", pdat->ecobli,
                         "ectime", pdat->ectime,
                         "elevetr", pdat->elevetr,
                         "elevref", pdat->elevref,
                         "eqntim", pdat->eqntim,
                         "erv", pdat->erv,
                         "etr", pdat->etr,
                         "etrn", pdat->etrn,
                         "etrtilt", pdat->etrtilt,
                         "gmst", pdat->gmst,
                         "hrang", pdat->hrang,
                         "julday", pdat->julday,
                         "lmst", pdat->lmst,
                         "mnanom", pdat->mnanom,
                         "mnlong", pdat->mnlong,
                         "rascen", pdat->rascen,
                         "press", pdat->press,
                         "prime", pdat->prime,
                         "sbcf", pdat->sbcf,
                         "sbwid", pdat->sbwid,
                         "sbrad", pdat->sbrad,
                         "sbsky", pdat->sbsky,
                         "solcon", pdat->solcon,
                         "ssha", pdat->ssha,
                         "sretr", pdat->sretr,
                         "ssetr", pdat->ssetr,
                         "temp", pdat->temp,
                         "tilt", pdat->tilt,
                         "tst", pdat->tst,
                         "tstfix", pdat->tstfix,
                         "unprime", pdat->unprime,
                         "utime", pdat->utime,
                         "zenetr", pdat->zenetr,
                         "zenref", pdat->zenref);
}

static struct PyMethodDef methods[] =
    {
        {"_solpos", (PyCFunction)_solpos, METH_VARARGS | METH_KEYWORDS, NULL},
        {NULL, NULL, 0, NULL}};

static struct PyModuleDef module =
    {
        PyModuleDef_HEAD_INIT,
        "_solpos",
        NULL,
        -1,
        methods};

PyMODINIT_FUNC PyInit__solpos(void)
{
    return PyModule_Create(&module);
}
