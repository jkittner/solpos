#include <Python.h>
#include "solpos00.h"

static PyObject *decode(long code, struct posdata *pdat)
{
    if (code & (1L << S_YEAR_ERROR))
    {
        PyErr_Format(PyExc_ValueError, "Please fix the year: %d [1950-2050]\n", pdat->year);
    }
    //   if ( code & (1L << S_MONTH_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the month: %d\n",
    //       pdat->month);
    //   if ( code & (1L << S_DAY_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the day-of-month: %d\n",
    //       pdat->day);
    //   if ( code & (1L << S_DOY_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the day-of-year: %d\n",
    //       pdat->daynum);
    //   if ( code & (1L << S_HOUR_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the hour: %d\n",
    //       pdat->hour);
    //   if ( code & (1L << S_MINUTE_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the minute: %d\n",
    //       pdat->minute);
    //   if ( code & (1L << S_SECOND_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the second: %d\n",
    //       pdat->second);
    //   if ( code & (1L << S_TZONE_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the time zone: %f\n",
    //       pdat->timezone);
    //   if ( code & (1L << S_INTRVL_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the interval: %d\n",
    //       pdat->interval);
    //   if ( code & (1L << S_LAT_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the latitude: %f\n",
    //       pdat->latitude);
    //   if ( code & (1L << S_LON_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the longitude: %f\n",
    //       pdat->longitude);
    //   if ( code & (1L << S_TEMP_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the temperature: %f\n",
    //       pdat->temp);
    //   if ( code & (1L << S_PRESS_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the pressure: %f\n",
    //       pdat->press);
    //   if ( code & (1L << S_TILT_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the tilt: %f\n",
    //       pdat->tilt);
    //   if ( code & (1L << S_ASPECT_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the aspect: %f\n",
    //       pdat->aspect);
    //   if ( code & (1L << S_SBWID_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the shadowband width: %f\n",
    //       pdat->sbwid);
    //   if ( code & (1L << S_SBRAD_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the shadowband radius: %f\n",
    //       pdat->sbrad);
    //   if ( code & (1L << S_SBSKY_ERROR) )
    //     fprintf(stderr, "S_decode ==> Please fix the shadowband sky factor: %f\n",
    //       pdat->sbsky);
    return NULL;
}

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
    decode(retval, pdat);
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
