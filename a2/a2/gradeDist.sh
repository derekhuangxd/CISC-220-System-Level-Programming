A=0
B=0
C=0
D=0
F=0
if [[ $# > 2 ]]
then
    echo "error: gradeDist.sh needs two arguments" >&2 
    exit 1
elif [[ ! -x $1 ]]
then
    echo "error: $1 is not an existing, excutable file" >&2 
    exit 2
elif [[ ! -d $2 ]]
then
    echo "error: $2 does not exist" >&2
    exit 3
else    
for X in ./"$2"/*
do
    if [[ -d $X ]]
    then
	(())
    elif [[ $(./$1 $X) == A ]]
    then
	((A+=1))
    elif [[ $(./$1 $X) == B ]]
    then
	((B+=1))
    elif [[ $(./$1 $X) == C ]]
    then
	((C+=1))
    elif [[ $(./$1 $X) == D ]]
    then
	((D+=1))
    elif [[ $(./$1 $X) == F ]]
    then
	((F+=1))
    fi
done

fi

echo "A: $A"
echo "B: $B"
echo "C: $C"
echo "D: $D"
echo "F: $F"
