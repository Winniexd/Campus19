/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:04:45 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 15:58:43 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int mysed(std::string fileName, std::string s1, std::string s2) {
    std::ifstream file;
    std::string line;
    std::string outstr;
    
   file.open(fileName.c_str(), std::ios::in);
    if (!file) {
        std::cout << "Unable to open file" << std::endl;
        return (2);
    }
    std::ofstream outfile;
    std::string outname = fileName.append(".replace");
    outfile.open(outname.c_str());
    if (!outfile)
        return 1;
    while (getline(file, line)) {
        outstr += line;
        if (!file.eof())
            outstr += "\n";
    }
    size_t p = outstr.find(s1);
    while (p < outstr.length()) {
        outstr.erase(p, s1.length());
        outstr.insert(p, s2);
        p = outstr.find(s1, p + s2.length());
    }
    outfile << outstr;
    file.close();
    outfile.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: ./mysed <infile> <s1> <s2>" << std::endl;
        return (1);
    }
    return (mysed(argv[1], argv[2], argv[3]));
}
