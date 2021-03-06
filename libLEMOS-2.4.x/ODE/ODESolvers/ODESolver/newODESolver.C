/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Description

\*---------------------------------------------------------------------------*/

#include "ODESolver.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::ODESolver> Foam::ODESolver::New
(
    const word& ODESolverTypeName,
    ODE& ode
)
{
    if (debug)
    {
        Info<< "Selecting ODE solver " << ODESolverTypeName << endl;
    }

    ODEConstructorTable::iterator cstrIter =
        ODEConstructorTablePtr_->find(ODESolverTypeName);

    if (cstrIter == ODEConstructorTablePtr_->end())
    {
        FatalErrorIn
        (
            "ODESolver::New(const word& ODESolverTypeName, ODE& ode)"
        )   << "Unknown ODESolver type "
            << ODESolverTypeName << endl << endl
            << "Valid  ODESolvers are : " << endl
            << ODEConstructorTablePtr_->toc()
            << exit(FatalError);
    }

    return autoPtr<ODESolver>(cstrIter()(ode));
}


// ************************************************************************* //
