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
. /home/apps/SPACK/spack/share/spack/setup-env.sh

spack load nvhpc@25.5

nvc++ --version


# ---- Run ----
cd $HOME/OpenACC

time ./filename
