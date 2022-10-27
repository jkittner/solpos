import shutil
import subprocess

import pytest

from solpos import solpos
from solpos import SolposResult


@pytest.fixture
def c_output(tmpdir):
    needed_files = ('solpos00.h', 'solpos.c', 'testing/test.c')
    for fname in needed_files:
        shutil.copy(fname, tmpdir)
    with tmpdir.as_cwd():
        # compile
        cmd = (
            'gcc', '-Wall', '-Werror', 'test.c',
            'solpos.c', '-o', 'test', '-lm',
        )
        subprocess.check_call(cmd)
        # run c code to generate file
        subprocess.check_call('./test')
        with open('c_output.txt') as f:
            data = [r.split('=') for r in f.read().splitlines()]

    values = {}
    for k, v in data:
        values[k] = float(v)

    yield values


def test_solpos():
    result = solpos(
        year=2022,
        month=10,
        day=27,
        hour=16,
        minute=26,
        second=0,
        timezone=2,
        latitude=51.44579,
        longitude=7.26274,
    )
    # these values were calculated using NREL's online SOLPOS calculator
    # (https://midcdmz.nrel.gov/solpos/solpos.html) with these settings:
    # https://midcdmz.nrel.gov/apps/solpos.pl?syear=2022&smonth=10&sday=27&eyear=2022&emonth=10&eday=27&step=1&stepunit=1&latitude=51.44579&longitude=7.26274&timezone=2&press=1013&temp=15&aspect=180&tilt=0&solcon=1367&sbwid=7.6&sbrad=31.7&sbsky=0.04&interval=0&field=0&field=1&field=34&field=2&field=3&field=4&field=10&field=11&field=14&field=15&field=16&field=27&field=28&field=25&field=24&field=31&field=5&field=18&field=33&field=6&field=7&field=8&field=9&field=12&field=13&field=21&field=22&field=23&field=26&field=29&field=30&field=17&field=32&field=20&field=19  # noqa: E501
    expected_result = SolposResult(
        year=2022,
        month=10,
        day=27,
        hour=16,
        minute=26,
        second=0,
        timezone=2,
        interval=0,
        latitude=51.44579,
        longitude=7.26274,
        amass=4.1934,
        ampress=4.1934,
        aspect=180.0,
        azim=227.9549,
        cosinc=0.2346,
        coszen=0.2346,
        dayang=294.9041,
        declin=-12.9005,
        eclong=214.1490,
        ecobli=23.4357,
        ectime=8335.1016,
        elevetr=13.5036,
        elevref=13.5683,
        eqntim=16.1428,
        erv=1.0128,
        etr=324.8205,
        etrn=1384.5477,
        etrtilt=324.8205,
        gmst=16.8288,
        hrang=47.7984,
        julday=59880.1016,
        lmst=259.6942,
        mnanom=292.6066,
        mnlong=215.9310,
        rascen=211.8958,
        press=1013,
        prime=1.3153,
        sbcf=1.0934,
        sbwid=7.6,
        sbrad=31.7,
        sbsky=0.04,
        solcon=1367,
        ssha=73.2986,
        sretr=501.6117,
        ssetr=1088.0009,
        temp=15.0,
        tilt=0,
        tst=911.1937,
        tstfix=-74.8063,
        unprime=0.7603,
        utime=14.4333,
        zenetr=76.4964,
        zenref=76.4317,
    )
    assert result == pytest.approx(expected_result, rel=1e-4)


def test_compare_to_c_calculated_values(c_output):
    expected_c = SolposResult(**c_output)
    result = solpos(
        year=2022,
        month=10,
        day=27,
        hour=16,
        minute=26,
        second=0,
        timezone=2,
        latitude=51.44579,
        longitude=7.26274,
    )
    assert result == pytest.approx(expected_c, rel=1e-6)
