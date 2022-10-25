from typing import NamedTuple

from _solpos import _solpos


class SolposResult(NamedTuple):
    year: int
    month: int
    day: int
    hour: int
    minute: int
    second: float
    timezone: float
    interval: int
    latitude: float
    longitude: float
    amass: float
    ampress: float
    aspect: float
    azim: float
    cosinc: float
    coszen: float
    dayang: float
    declin: float
    eclong: float
    ecobli: float
    ectime: float
    elevetr: float
    elevref: float
    eqntim: float
    erv: float
    etr: float
    etrn: float
    etrtilt: float
    gmst: float
    hrang: float
    julday: float
    lmst: float
    mnanom: float
    mnlong: float
    rascen: float
    press: float
    prime: float
    sbcf: float
    sbwid: float
    sbrad: float
    sbsky: float
    solcon: float
    ssha: float
    sretr: float
    ssetr: float
    temp: float
    tilt: float
    tst: float
    tstfix: float
    unprime: float
    utime: float
    zenetr: float
    zenref: float


def solpos(
        year: int,
        month: int,
        day: int,
        hour: int,
        minute: int,
        second: int,
        timezone: float,
        latitude: float,
        longitude: float,
        interval: int = 0,
        aspect: float = 180.0,
        press: float = 1013.0,
        sbwid: float = 7.6,
        sbrad: float = 31.7,
        sbsky: float = 0.04,
        solcon: float = 1367.0,
        temp: float = 15.0,
        tilt: float = 0.0,
) -> SolposResult:
    restult = _solpos(
        year=year,
        month=month,
        day=day,
        hour=hour,
        minute=minute,
        second=second,
        timezone=timezone,
        latitude=latitude,
        longitude=longitude,
        interval=interval,
        aspect=aspect,
        press=press,
        sbwid=sbwid,
        sbrad=sbrad,
        sbsky=sbsky,
        solcon=solcon,
        temp=temp,
        tilt=tilt,
    )
    return SolposResult(**restult)
