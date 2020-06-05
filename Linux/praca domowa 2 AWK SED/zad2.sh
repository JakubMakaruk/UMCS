#!/bin/bash

# 1) female->0, male->1
#sed 's/female/0/g;s/male/1/g' StudentsPerformance.csv

# 2) none->0
#sed 's/none/0/g' StudentsPerformance.csv

# 3) group D->D(każda grupa)
#sed 's/group A/A/g;s/group B/B/g;s/group C/C/g;s/group D/D/g' StudentsPerformance.cs

# wszystko razem
sed 's/female/0/g;s/male/1/g;s/none/0/g;s/group A/A/g;s/group B/B/g;s/group C/C/g;s/group D/D/g' StudentsPerformance.csv
