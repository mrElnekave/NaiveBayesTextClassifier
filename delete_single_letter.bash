#!/usr/bin/bash

cat $* \
    | sed -e 's#<S> a </S>##' \
    | sed -e 's#<S> b </S>##' \
    | sed -e 's#<S> c </S>##' \
    | sed -e 's#<S> d </S>##' \
    | sed -e 's#<S> e </S>##' \
    | sed -e 's#<S> f </S>##' \
    | sed -e 's#<S> g </S>##' \
    | sed -e 's#<S> h </S>##' \
    | sed -e 's#<S> i </S>##' \
    | sed -e 's#<S> j </S>##' \
    | sed -e 's#<S> k </S>##' \
    | sed -e 's#<S> l </S>##' \
    | sed -e 's#<S> m </S>##' \
    | sed -e 's#<S> n </S>##' \
    | sed -e 's#<S> o </S>##' \
    | sed -e 's#<S> p </S>##' \
    | sed -e 's#<S> q </S>##' \
    | sed -e 's#<S> r </S>##' \
    | sed -e 's#<S> s </S>##' \
    | sed -e 's#<S> t </S>##' \
    | sed -e 's#<S> u </S>##' \
    | sed -e 's#<S> v </S>##' \
    | sed -e 's#<S> w </S>##' \
    | sed -e 's#<S> x </S>##' \
    | sed -e 's#<S> y </S>##' \
    | sed -e 's#<S> z </S>##' 