# Project Part 1: Reading a File into an ASList
**Due:** Nov 10th, 2025

---

## 1. Project Description
One aspect of data structures that we have not yet explored is their practical application to real-world datasets.  
The purpose of this project is to apply data structures to a simple dataset.  

The project consists of two phases, with this phase focusing on selecting an online dataset and loading it into an **Array-based Sorted List (ASList)**.  
The data will be sorted based on a selected attribute/column.

---

## 2. Project Tasks
You are required to complete the following tasks:

1. **Dataset Selection:**  
   Find a dataset online (preferably in `.csv` format) that interests you from either a personal or professional perspective.  
   - If you need assistance finding a dataset, [Kaggle](https://www.kaggle.com/) is a great resource for publicly available datasets.  
   - If your dataset is not in `.csv` format, you will need to convert it before proceeding.  
   - Contact the instructor for assistance if needed.

2. **Dataset Preparation:**  
   Open the dataset in Excel and identify at least three relevant variables (at least one of which must be numeric).  
   - Remove unnecessary variables and reduce the dataset to a maximum of **1,000 rows** if necessary.  
   - Save the modified dataset and include it in your submission.

3. **Modifying the ASList Structure:**  
   Using the modified dataset, adapt the ASList data structure to match your selected variables.  
   - Choose an attribute/column as the key for sorting and decide whether sorting should be in ascending or descending order.  
   - For reference, the provided **CCFraud** example sorts transactions by “amount” in descending order.

4. **Implementing in C++:**  
   Modify or create a C++ program that:
   - Loads the dataset into your ASList structure.  
   - Prints the sorted data row by row.  
   
   Since an ASList is used, the printed output should be sorted based on the chosen attribute.

---

## 3. Important Notes
- It is recommended that you use the **CCFraud** example on Blackboard as a starting point because:  
  1. You only need a small subset of the ASList functionality for the project. CCFraud includes a simplified, reduced ASList structure (**ASListR**) that is appropriate for this project.  
  2. It already contains a `main` function for loading a `.csv` file into the ASList, which can be easily adapted to your own project.  
- **Note:** The CCFraud dataset cannot be used for this project.

---

## 4. Project Outline (Required Submission)
In addition to the code, you must submit a **project outline** (½–1 page) containing:
- Your name.  
- The dataset’s title.  
- **Motivation:** A brief discussion of your interest in the dataset (general or dataset-specific).  
- **Data Description:**  
  1. The dataset’s source (e.g., Kaggle or a custom dataset).  
  2. The selected variables of interest.  
  3. Steps taken to prepare the dataset, including the selected key and order (ascending or descending).

---

## 5. Extra Credit Opportunity
If you want to improve your grade on the first exam, you may complete the following **extra-credit task**:

- After printing all records in the list, prompt the user to input a value that belongs to the chosen sorting attribute.  
- Implement extra functionality to:  
  1. If the column is **numeric**, print only the values **greater than** the input.  
  2. If the column is **non-numeric** (e.g., a string), print only the values **equal to** the input.  

This extra credit is worth **1 point for every 5 points missed** on the first exam.

---

## 6. Submission Instructions
Submit a `.zip` file named:  
`<LastName>_<FirstName>_ProjPart1.zip`

Your submission must include:
- The project outline (`.docx` or `.pdf` format).  
- The modified `.csv` file.  
- The modified `ASList.cpp` and `ASList.h` (or `ASListR.cpp` / `ASListR.h`) files.  
- The `main` function used to load and print the dataset.

**Important:**  
Do **not** submit the project to Gradescope.  
Submit it directly on **Blackboard**.

**Compile**
```bash
g++ main.cpp ASList.cpp -o program
./program
```
