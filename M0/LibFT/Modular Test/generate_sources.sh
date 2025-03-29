#!/bin/bash

# Script de génération des sources pour le Makefile

# Répertoires à explorer
SUBDIRS="SubMod1 SubMod2"

# Fichier de sortie
OUTPUT_FILE="sources.mk"

# Début du fichier de configuration
echo "# Sources générées automatiquement" > $OUTPUT_FILE
echo "SRCS =" >> $OUTPUT_FILE

# Fonction pour extraire les sources d'un Makefile
extract_sources() {
    local makefile=$1
    if [ -f "$makefile" ]; then
        # Extraction des sources en cherchant la ligne SRCS
        sources=$(grep "^SRCS\s*=" "$makefile" | sed -e 's/^SRCS\s*=\s*//')
        
        # Préfixer les sources avec le chemin du répertoire
        local dir=$(dirname "$makefile")
        for src in $sources; do
            echo "SRCS += $dir/$src" >> $OUTPUT_FILE
        done
    fi
}

# Exploration des sous-répertoires
for dir in $SUBDIRS; do
    if [ -d "$dir" ]; then
        # Cherche le Makefile dans le sous-répertoire
        extract_sources "$dir/Makefile"
    fi
done

# Ajoute les fichiers du répertoire courant si un Makefile local existe
if [ -f Makefile ]; then
    local_sources=$(grep "^SRCS\s*=" Makefile | sed -e 's/^SRCS\s*=\s*//')
    for src in $local_sources; do
        echo "SRCS += $src" >> $OUTPUT_FILE
    done
fi

echo "Sources générées dans $OUTPUT_FILE"