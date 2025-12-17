#!/bin/bash
#SBATCH --job-name=OpenACC
#SBATCH --partition=gpu
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --gres=gpu:1
#SBATCH --time=00:05:00
#SBATCH --output=out_%j.txt
#SBATCH --error=err_%j.txt

ulimit -s unlimited
# ---- Load modules ----
ml spack
. /home/apps/spack/share/spack/setup-env.sh
spack load gcc/hp5qs7t
spack load cuda/kr6npmd

export PATH=$HOME/AKASH/nvhpc/Linux_x86_64/25.11/compilers/bin:$PATH
export NVHPC=$HOME/AKASH/nvhpc/Linux_x86_64/25.11
export LD_LIBRARY_PATH=$NVHPC/compilers/lib:$LD_LIBRARY_PATH
export MANPATH=$NVHPC/compilers/man:$MANPATH
which gcc
gcc --version

which g++
g++ --version

which nvc++
nvc++ --version


# ---- Run ----
cd $HOME/AKASH/OPENACC

./02.vector_addition_parallel
