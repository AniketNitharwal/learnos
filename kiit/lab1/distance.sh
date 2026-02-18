#!/bin/bash

echo "Distance Conversion to Meters"

echo "Enter distance in kilometers"
read km

echo "Enter distance in meters"
read m

echo "Enter distance in centimeters"
read cm

meters=$(echo "$km * 1000 + $m + $cm / 100" | bc)

echo "Total distance in meters = $meters m"
