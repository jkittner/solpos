#include <stdio.h>
#include <stdlib.h>

#include "solpos00.h"

int
main()
{
    struct posdata pd, *pdat;
    pdat = &pd;
    S_init(pdat);
    pdat->function = ~S_DOY;

    // test values
    pdat->year = 2022;
    pdat->month = 10;
    pdat->day = 27;
    pdat->hour = 16;
    pdat->minute = 26;
    pdat->second = 0;
    pdat->timezone = 2;
    pdat->latitude = 51.44579;
    pdat->longitude = 7.26274;

    long retval = S_solpos(pdat);
    S_decode(retval, pdat);

    FILE *fptr;
    const char *fname = "c_output.txt";
    fptr = fopen("c_output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file: %s\n", fname);
        exit(1);
    }
    fprintf(fptr, "year=%d\n", pdat->year);
    fprintf(fptr, "month=%d\n", pdat->month);
    fprintf(fptr, "day=%d\n", pdat->day);
    fprintf(fptr, "hour=%d\n", pdat->hour);
    fprintf(fptr, "minute=%d\n", pdat->minute);
    fprintf(fptr, "second=%d\n", pdat->second);
    fprintf(fptr, "timezone=%f\n", pdat->timezone);
    fprintf(fptr, "interval=%d\n", pdat->interval);
    fprintf(fptr, "latitude=%f\n", pdat->latitude);
    fprintf(fptr, "longitude=%f\n", pdat->longitude);
    fprintf(fptr, "amass=%f\n", pdat->amass);
    fprintf(fptr, "ampress=%f\n", pdat->ampress);
    fprintf(fptr, "aspect=%f\n", pdat->aspect);
    fprintf(fptr, "azim=%f\n", pdat->azim);
    fprintf(fptr, "cosinc=%f\n", pdat->cosinc);
    fprintf(fptr, "coszen=%f\n", pdat->coszen);
    fprintf(fptr, "dayang=%f\n", pdat->dayang);
    fprintf(fptr, "declin=%f\n", pdat->declin);
    fprintf(fptr, "eclong=%f\n", pdat->eclong);
    fprintf(fptr, "ecobli=%f\n", pdat->ecobli);
    fprintf(fptr, "ectime=%f\n", pdat->ectime);
    fprintf(fptr, "elevetr=%f\n", pdat->elevetr);
    fprintf(fptr, "elevref=%f\n", pdat->elevref);
    fprintf(fptr, "eqntim=%f\n", pdat->eqntim);
    fprintf(fptr, "erv=%f\n", pdat->erv);
    fprintf(fptr, "etr=%f\n", pdat->etr);
    fprintf(fptr, "etrn=%f\n", pdat->etrn);
    fprintf(fptr, "etrtilt=%f\n", pdat->etrtilt);
    fprintf(fptr, "gmst=%f\n", pdat->gmst);
    fprintf(fptr, "hrang=%f\n", pdat->hrang);
    fprintf(fptr, "julday=%f\n", pdat->julday);
    fprintf(fptr, "lmst=%f\n", pdat->lmst);
    fprintf(fptr, "mnanom=%f\n", pdat->mnanom);
    fprintf(fptr, "mnlong=%f\n", pdat->mnlong);
    fprintf(fptr, "rascen=%f\n", pdat->rascen);
    fprintf(fptr, "press=%f\n", pdat->press);
    fprintf(fptr, "prime=%f\n", pdat->prime);
    fprintf(fptr, "sbcf=%f\n", pdat->sbcf);
    fprintf(fptr, "sbwid=%f\n", pdat->sbwid);
    fprintf(fptr, "sbrad=%f\n", pdat->sbrad);
    fprintf(fptr, "sbsky=%f\n", pdat->sbsky);
    fprintf(fptr, "solcon=%f\n", pdat->solcon);
    fprintf(fptr, "ssha=%f\n", pdat->ssha);
    fprintf(fptr, "sretr=%f\n", pdat->sretr);
    fprintf(fptr, "ssetr=%f\n", pdat->ssetr);
    fprintf(fptr, "temp=%f\n", pdat->temp);
    fprintf(fptr, "tilt=%f\n", pdat->tilt);
    fprintf(fptr, "tst=%f\n", pdat->tst);
    fprintf(fptr, "tstfix=%f\n", pdat->tstfix);
    fprintf(fptr, "unprime=%f\n", pdat->unprime);
    fprintf(fptr, "utime=%f\n", pdat->utime);
    fprintf(fptr, "zenetr=%f\n", pdat->zenetr);
    fprintf(fptr, "zenref=%f\n", pdat->zenref);
    fclose(fptr);
    printf("written data to %s\n", fname);
    return 0;
}
