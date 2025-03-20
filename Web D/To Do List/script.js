document.addEventListener("DOMContentLoaded", function () {
  const taskInput = document.getElementById("taskInput");
  const dateInput = document.getElementById("date");
  const addTaskButton = document.getElementById("addTask");
  const taskTableBody = document.getElementById("taskTableBody");

  addTaskButton.addEventListener("click", function () {
      const taskValue = taskInput.value.trim();
      const dateValue = dateInput.value;

      if (taskValue === "" || dateValue === "") {
          alert("⚠️ Please enter both task and date.");
          return;
      }

      const row = document.createElement("tr");

      const taskCol = document.createElement("td");
      taskCol.textContent = taskValue;
      row.appendChild(taskCol);

      const dateCol = document.createElement("td");
      dateCol.textContent = dateValue;
      row.appendChild(dateCol);

      const actionCol = document.createElement("td");
      actionCol.classList.add("action-buttons");

      const editButton = document.createElement("button");
      editButton.textContent = "✏️ Edit";
      editButton.classList.add("edit-btn");

      const deleteButton = document.createElement("button");
      deleteButton.textContent = "🗑️ Delete";
      deleteButton.classList.add("delete-btn");

      actionCol.appendChild(editButton);
      actionCol.appendChild(deleteButton);
      row.appendChild(actionCol);

      taskTableBody.appendChild(row);

      editButton.addEventListener("click", function () {
          const newTask = prompt("Edit your task:", taskCol.textContent);
          if (newTask) taskCol.textContent = newTask;
      });

      deleteButton.addEventListener("click", function () {
          taskTableBody.removeChild(row);
      });

      taskInput.value = "";
      dateInput.value = "";
  });
});
