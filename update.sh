#!/bin/sh
rm -rf build*
rm -rf MLS-filtering/build
rm -rf statistic-outlier-removal/build
git add .
git commit -m "update"
git push origin master
