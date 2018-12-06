MATLAB="/Applications/MATLAB_R2018a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/kevinjoe/Library/Application Support/MathWorks/MATLAB/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for run_usrp_rx" > run_usrp_rx_mex.mki
echo "CC=$CC" >> run_usrp_rx_mex.mki
echo "CFLAGS=$CFLAGS" >> run_usrp_rx_mex.mki
echo "CLIBS=$CLIBS" >> run_usrp_rx_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> run_usrp_rx_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> run_usrp_rx_mex.mki
echo "CXX=$CXX" >> run_usrp_rx_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> run_usrp_rx_mex.mki
echo "CXXLIBS=$CXXLIBS" >> run_usrp_rx_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> run_usrp_rx_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> run_usrp_rx_mex.mki
echo "LDFLAGS=$LDFLAGS" >> run_usrp_rx_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> run_usrp_rx_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> run_usrp_rx_mex.mki
echo "Arch=$Arch" >> run_usrp_rx_mex.mki
echo "LD=$LD" >> run_usrp_rx_mex.mki
echo OMPFLAGS= >> run_usrp_rx_mex.mki
echo OMPLINKFLAGS= >> run_usrp_rx_mex.mki
echo "EMC_COMPILER=clang" >> run_usrp_rx_mex.mki
echo "EMC_CONFIG=optim" >> run_usrp_rx_mex.mki
"/Applications/MATLAB_R2018a.app/bin/maci64/gmake" -j 1 -B -f run_usrp_rx_mex.mk
