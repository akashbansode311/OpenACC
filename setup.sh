ml spack
. /home/apps/spack/share/spack/setup-env.sh
spack load gcc/hp5qs7t
spack load cuda/kr6npmd

export PATH=$HOME/nvhpc/Linux_x86_64/25.11/compilers/bin:$PATH
export NVHPC=$HOME/nvhpc/Linux_x86_64/25.11
export LD_LIBRARY_PATH=$NVHPC/compilers/lib:$LD_LIBRARY_PATH
export MANPATH=$NVHPC/compilers/man:$MANPATH
