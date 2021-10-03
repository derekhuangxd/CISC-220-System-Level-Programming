if [[ $# > 1 ]]
then
    echo "error: wrong number of arguments for pigLatin.sh (needs exactly one)" >&2
    exit 1

elif [[ ${1:0:1} == a || ${1:0:1} == e || ${1:0:1} == i || ${1:0:1} == o || ${1:0:1} == u ]]
then
    echo "$1"way

elif [[ ${1:0:1} != a || ${1:0:1} != e || ${1:0:1} != i || ${1:0:1} != o || ${1:0:1} != u ]]
then
    TEMPWORD=$1
    if [[ ${#TEMPWORD} == 1 ]]
    then
	echo "$TEMPWORD"ay
    else
    
    while ! [[ ${TEMPWORD:0:1} == a || ${TEMPWORD:0:1} == e || ${TEMPWORD:0:1} == i || ${TEMPWORD:0:1} == o || ${TEMPWORD:0:1} == u ]]
    do
	TEMPWORD=${TEMPWORD/"${TEMPWORD:0:1}"/}${TEMPWORD:0:1}
    done
	echo "$TEMPWORD"ay
    fi
fi

