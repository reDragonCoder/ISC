using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinFormsNameAge.Model;

namespace WinFormsNameAge.Data
{
    public class User
    {
        List<UserModel> list = new List<UserModel>();
        /// <summary>
        /// Save the users
        /// </summary>
        /// <param name="model">user data</param>
        public void Save(UserModel model)
        {
            list.Add(model);
        }
        /// <summary>
        /// See al users
        /// </summary>
        /// <returns>users data</returns>
        public List<UserModel> See()
        {
            return list;
        }
    }
}
